# @param {String} path
# @return {String}
def simplify_path(path)
  components = path.split('/').select {|x| not x.empty?}
  res = []
  components.each do |component|
    if component == '..'
      res.pop
    elsif component != '.'
      res.push component
    end
  end
  '/' + res.join('/')
end
