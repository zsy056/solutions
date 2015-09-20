# @param {Integer} a
# @param {Integer} b
# @param {Integer} c
# @param {Integer} d
# @param {Integer} e
# @param {Integer} f
# @param {Integer} g
# @param {Integer} h
# @return {Integer}
def compute_area(a, b, c, d, e, f, g, h)
  overlap = if c < e || a > g || d < f || b > h
              0
            else
              xs = [a, c, e, g].sort
              ys = [b, d, f, h].sort
              (xs[2] - xs[1]) * (ys[2] - ys[1])
            end
  (c - a) * (d - b) + (g - e) * (h - f) - overlap
end
