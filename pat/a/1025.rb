#!/usr/bin/env ruby

class Student
  attr_accessor :reg_num, :score, :location_num, :local_rank, :final_rank
  def initialize(reg_num, score, location_num)
    @reg_num = reg_num
    @score = score
    @location_num = location_num
    @local_rank = 0
    @final_rank = 0
  end

  def <=>(other)
    self.reg_num <=> other.reg_num
  end

  def to_s
    "#{@reg_num} #{@final_rank} #{@location_num} #{@local_rank}"
  end
end

def local_lists(students)
  scores = Array.new(101) { [] }
  students.each { |s| scores[s.score] << s }
  update_score(scores) { |s, rank| s.local_rank = rank }
  scores
end

def global_lists(locations)
  tscores = Array.new(101) { [] } 
  locations.each do |scores|
    scores.each_with_index do |score, index|
      tscores[index].concat(score)
    end
  end
  tscores.each { |score| score.sort! }
  update_score(tscores) { |s, rank| s.final_rank = rank }
  tscores
end

def update_score(scores)
  rank = 1
  scores.reverse_each do |score|
    score.each { |student| yield(student, rank) }
    rank += score.size
  end
end

inputs = $stdin.readlines
n = inputs[0].to_i
locations = Array.new n
curr_line = 1
num_studens = 0
n.times do |i| 
  m = inputs[curr_line].to_i
  curr_line += 1
  num_studens += m
  students = Array.new m
  m.times do |j|
    line = inputs[curr_line].split ' '
    curr_line += 1
    students[j] = Student.new(line[0], line[1].to_i, i+1)
  end
  locations[i] = students 
end

locations_scores = locations.map { |students| local_lists students }
tscores = global_lists locations_scores 

puts num_studens 
tscores.reverse_each do |score|
  score.each { |s| puts s.to_s }
end
