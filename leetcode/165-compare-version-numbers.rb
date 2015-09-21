# @param {String} version1
# @param {String} version2
# @return {Integer}
def compare_version(version1, version2)
  transform(version1) <=> transform(version2)
end

def transform(version)
  v = version.split('.').map {|x| x.to_i}
  while v[-1] == 0
    v.pop
  end
  v
end
