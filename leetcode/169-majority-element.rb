# @param {Integer[]} nums
# @return {Integer}
def majority_element(nums)
  counter = 0
  maj = 0
  nums.each do |n|
    if counter == 0
      maj = n
      counter = 1
    elsif maj == n
      counter += 1
    else 
      counter -= 1
    end 
  end
  maj
end
