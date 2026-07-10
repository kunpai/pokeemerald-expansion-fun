#!/usr/bin/env python3
"""
Recolor existing Poké Ball art to create Magma and Aqua Ball variants.
Takes the clean, game-quality Poké Ball sprites and recolors them
by directly remapping palette indices, then draws M/A emblems.
"""
import os
from PIL import Image

EXPANSION = "/Users/kunpai/Desktop/prototypes/pokeemerald-project/pokeemerald-expansion"

def recolor_indexed_png(src_path, palette_remap, out_path, pixel_overrides=None):
    """Recolor an indexed PNG by remapping specific palette entries.
    palette_remap: dict of {index: (r, g, b)} to replace in the palette.
    pixel_overrides: list of (x, y, palette_index) to set individual pixels.
    """
    img = Image.open(src_path)
    assert img.mode == 'P', f"Expected indexed PNG, got {img.mode}: {src_path}"
    
    new_img = img.copy()
    palette = list(img.getpalette())
    
    for idx, (r, g, b) in palette_remap.items():
        palette[idx*3] = r
        palette[idx*3+1] = g
        palette[idx*3+2] = b
    
    new_img.putpalette(palette)
    
    # Apply individual pixel overrides (for drawing letters)
    if pixel_overrides:
        pixels = new_img.load()
        for (x, y, pal_idx) in pixel_overrides:
            w, h = new_img.size
            if 0 <= x < w and 0 <= y < h:
                pixels[x, y] = pal_idx
    
    new_img.save(out_path)
    print(f"Saved: {out_path}")

def write_pal_file(palette_remap, src_path, out_path):
    """Write a JASC-PAL file based on the source image with remapped colors."""
    img = Image.open(src_path)
    palette = list(img.getpalette()[:48])
    
    for idx, (r, g, b) in palette_remap.items():
        if idx < 16:
            palette[idx*3] = r
            palette[idx*3+1] = g
            palette[idx*3+2] = b
    
    with open(out_path, 'w') as f:
        f.write("JASC-PAL\r\n")
        f.write("0100\r\n")
        f.write("16\r\n")
        for i in range(16):
            r = palette[i*3]
            g = palette[i*3+1]
            b = palette[i*3+2]
            f.write(f"{r} {g} {b}\r\n")
    print(f"Saved palette: {out_path}")


def make_letter_M_pixels(letter_pal_idx):
    """Return pixel overrides to draw 'M' on the top half of a 24x24 ball icon.
    The letter is drawn using the given palette index (dark color for contrast).
    Coordinates are tuned for the standard Poké Ball shape.
    
    M pattern (7 wide x 5 tall), centered at roughly x=8..14, y=4..8:
    X . . . . . X
    X X . . . X X
    X . X . X . X
    X . . X . . X
    X . . . . . X
    """
    ox, oy = 8, 4  # top-left origin of the letter area
    m_pixels = [
        # Row 0: X . . . . . X
        (ox+0, oy+0), (ox+6, oy+0),
        # Row 1: X X . . . X X
        (ox+0, oy+1), (ox+1, oy+1), (ox+5, oy+1), (ox+6, oy+1),
        # Row 2: X . X . X . X
        (ox+0, oy+2), (ox+2, oy+2), (ox+4, oy+2), (ox+6, oy+2),
        # Row 3: X . . X . . X
        (ox+0, oy+3), (ox+3, oy+3), (ox+6, oy+3),
        # Row 4: X . . . . . X
        (ox+0, oy+4), (ox+6, oy+4),
    ]
    return [(x, y, letter_pal_idx) for (x, y) in m_pixels]


def make_letter_A_pixels(letter_pal_idx):
    """Return pixel overrides to draw 'A' on the top half of a 24x24 ball icon.
    
    A pattern (7 wide x 5 tall), centered at roughly x=8..14, y=4..8:
    . . . X . . .
    . . X . X . .
    . X . . . X .
    . X X X X X .
    X . . . . . X
    """
    ox, oy = 8, 4
    a_pixels = [
        # Row 0: . . . X . . .
        (ox+3, oy+0),
        # Row 1: . . X . X . .
        (ox+2, oy+1), (ox+4, oy+1),
        # Row 2: . X . . . X .
        (ox+1, oy+2), (ox+5, oy+2),
        # Row 3: . X X X X X .
        (ox+1, oy+3), (ox+2, oy+3), (ox+3, oy+3), (ox+4, oy+3), (ox+5, oy+3),
        # Row 4: X . . . . . X
        (ox+0, oy+4), (ox+6, oy+4),
    ]
    return [(x, y, letter_pal_idx) for (x, y) in a_pixels]


if __name__ == "__main__":
    # ============================================================
    # BAG ICONS (24x24)
    # Poké Ball palette indices:
    #   0: (180,180,180) bg
    #   1: (49,49,49) dark outline  <-- use for letter
    #   7: (156,74,57) dark red
    #   9: (222,90,57) medium red
    #  10: (255,148,57) main red/orange body
    #  11: (255,213,57) red highlight
    # ============================================================
    
    poke_icon = os.path.join(EXPANSION, "graphics/items/icons/poke_ball.png")
    LETTER_IDX = 1  # dark outline color — contrasts well against ball body
    
    # --- MAGMA BALL ---
    magma_icon_remap = {
        7:  (115, 24, 24),
        9:  (172, 41, 41),
        10: (213, 57, 24),
        11: (255, 106, 57),
    }
    magma_letter = make_letter_M_pixels(LETTER_IDX)
    recolor_indexed_png(poke_icon, magma_icon_remap,
                        os.path.join(EXPANSION, "graphics/items/icons/magma_ball.png"),
                        pixel_overrides=magma_letter)
    write_pal_file(magma_icon_remap, poke_icon,
                   os.path.join(EXPANSION, "graphics/items/icon_palettes/magma_ball.pal"))
    
    # --- AQUA BALL ---
    aqua_icon_remap = {
        7:  (16, 49, 115),
        9:  (24, 82, 172),
        10: (41, 123, 213),
        11: (90, 180, 255),
    }
    aqua_letter = make_letter_A_pixels(LETTER_IDX)
    recolor_indexed_png(poke_icon, aqua_icon_remap,
                        os.path.join(EXPANSION, "graphics/items/icons/aqua_ball.png"),
                        pixel_overrides=aqua_letter)
    write_pal_file(aqua_icon_remap, poke_icon,
                   os.path.join(EXPANSION, "graphics/items/icon_palettes/aqua_ball.pal"))
    
    # ============================================================
    # THROW SPRITES (16x48) — no letters, just recolor
    # ============================================================
    
    poke_throw = os.path.join(EXPANSION, "graphics/balls/poke.png")
    
    magma_throw_remap = {
        1: (90, 0, 0),
        2: (139, 16, 0),
        3: (189, 41, 24),
        4: (246, 123, 82),
    }
    recolor_indexed_png(poke_throw, magma_throw_remap,
                        os.path.join(EXPANSION, "graphics/balls/magma.png"))
    
    aqua_throw_remap = {
        1: (0, 41, 90),
        2: (0, 65, 139),
        3: (24, 106, 189),
        4: (82, 172, 246),
    }
    recolor_indexed_png(poke_throw, aqua_throw_remap,
                        os.path.join(EXPANSION, "graphics/balls/aqua.png"))
    
    # ============================================================
    # OVERWORLD SPRITES (80x32) — no letters, just recolor
    # ============================================================
    
    poke_ow = os.path.join(EXPANSION, "graphics/object_events/pics/misc/ball_poke.png")
    
    magma_ow_remap = {
        11: (189, 57, 41),
        12: (131, 24, 16),
        13: (74, 0, 0),
    }
    recolor_indexed_png(poke_ow, magma_ow_remap,
                        os.path.join(EXPANSION, "graphics/object_events/pics/misc/ball_magma.png"))
    
    aqua_ow_remap = {
        11: (57, 131, 205),
        12: (24, 82, 156),
        13: (0, 41, 90),
    }
    recolor_indexed_png(poke_ow, aqua_ow_remap,
                        os.path.join(EXPANSION, "graphics/object_events/pics/misc/ball_aqua.png"))
    
    print("\n=== Done! All ball art recolored with M/A emblems. ===")
