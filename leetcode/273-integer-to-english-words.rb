# @param {Integer} num
# @return {String}
def number_to_words(num)
  if num <= 20
    DIGITS[num]
  else
    LEVEL.each do |level|
      high = num / level[1]
      next if high == 0
      low = num - high * level[1]
      a = number_to_words(high)
      b = low == 0 ? nil : number_to_words(low)
      return [a, level[0], b].select { |i| not i.nil? }.join ' '
    end
    idx = num / 10
    [TENS[idx], num % 10 == 0 ? nil : DIGITS[num % 10]].select { |i| not i.nil? }.join ' '
  end
end

DIGITS = ['Zero', 'One', 'Two', 'Three', 'Four', 'Five', 'Six', 'Seven', 'Eight', 'Nine',
          'Ten', 'Eleven', 'Twelve', 'Thirteen', 'Fourteen', 'Fifteen', 'Sixteen', 'Seventeen', 'Eighteen', 'Nineteen',
          'Twenty']
TENS = [nil, nil, 'Twenty', 'Thirty', 'Forty', 'Fifty', 'Sixty', 'Seventy', 'Eighty', 'Ninety']
LEVEL = [['Billion', 1000000000], ['Million', 1000000], ['Thousand', 1000], ['Hundred', 100]]
