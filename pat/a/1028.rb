#!/usr/bin/env ruby
# TLE on the last case

class Student
  attr_accessor :num, :name, :score, :numi
  def initialize(line)
    words = line.split ' '
    @num = words[0]
    @numi = @num.to_i
    @name = words[1]
    @score = words[2].to_i
  end

  def <=>(other)
    @numi <=> other.numi
  end

  def to_s
    "#{@num} #{@name} #{@score}"
  end
end

def compare(a, b)
  res = yield(a, b)
  if res == 0
    a <=> b
  else
    res
  end
end

if __FILE__ == $0
  lines = STDIN.readlines
  field = lines[0].split(' ')[1].to_i
  lines = lines[1,lines.size - 1]
  students = lines.map { |s| Student.new s }
  if field == 1
    students.sort!
  elsif field == 2
    students.sort! do |x, y|
      compare(x, y) do |a, b|
        a.name <=> b.name
      end
    end
  else
    students.sort! do |x, y|
      compare(x, y) do |a, b|
        a.score <=> b.score
      end
    end
  end
  puts students
end
