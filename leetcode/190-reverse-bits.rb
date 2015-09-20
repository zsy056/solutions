def reverse_bits(n)
  ("%032b" % n).reverse.to_i(2)
end
