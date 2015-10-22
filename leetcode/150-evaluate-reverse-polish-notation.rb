# @param {String[]} tokens
# @return {Integer}
def eval_rpn(tokens)
  stack = []  
  tokens.each do |token|
    res = 0
    if token == '+'
      res = stack[-2] + stack[-1]
    elsif token == '-'
      res = stack[-2] - stack[-1]
    elsif token == '*'
      res = stack[-2] * stack[-1]
    elsif token == '/'
      res = (stack[-2] / stack[-1].to_f).to_i
    else
      res = token.to_i
    end
    stack.pop 2 if ['+', '-', '*', '/'].include? token
    stack.push res
  end
  stack[0]
end

