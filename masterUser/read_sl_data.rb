#!/usr/bin/ruby
# Read SL log files
# hi@siri.sh

require 'csv'


def sl_to_csv(filename)

  #@filename = "d00007"
  @filename = filename

  @raw = File.open(@filename)

  @num_of_data_points = nil
  @num_of_variables = nil
  @num_of_samples = nil
  @sampling_rate = nil
  @variables = nil

  @values = []

  ### Get the plaintext headers ##########################
  @raw.each_line do |line|
    
    # line number 2
    if @num_of_variables != nil and @variables == nil
      @variables = line.split
      0.upto(@num_of_variables.to_i-1) do |i|
        puts "#{@variables[2*i]} (#{@variables[2*i+1]})"
        eval "@#{@variables[2*i]} = Array.new"
      end
    end
    
    # line number 1
    @num_of_data_points ||= line.split[0]
    @num_of_variables ||= line.split[1]
    @num_of_samples ||= line.split[2]
    @sampling_rate ||= line.split[3]
    
  end

  puts "Number of variables: #{@num_of_variables}"
  puts "Number of samples: #{@num_of_samples}"
  puts "Sampling rate: #{@sampling_rate}"


  ### Get the binary encoded data ###########################
  @raw = File.read(@filename)
  #@floats = @raw[1388..-1]
  @floats = @raw[-(@num_of_data_points.to_i*4)..-1]
  puts @floats.length

  index = 0
  (0..@num_of_data_points.to_i-1).reverse_each do |i|
    #p -i*4-1
    #p @floats[-i*4-4..-i*4-1].unpack('g')
    #@values += @floats[-i*4-4..-i*4-1].unpack('f')
    #p @variables[2*(index%81)]
    eval "@#{@variables[2*(index % @num_of_variables.to_i)]} += @floats[-i*4-4..-i*4-1].unpack('g')" #if index%81 == 0
    index+=1
  end

  p @variables
  p @values
  p @time
  #puts @values.length


  ### WRITE OUTPUT FILE ##############################
  @out = CSV.open("#{@filename}.csv", "wb")
  variable_list = []
  0.upto(@num_of_variables.to_i-1) do |i|
    variable_list +=["#{@variables[2*i]} (#{@variables[2*i+1]})"]
  end
  p variable_list
  @out << variable_list

  0.upto(@num_of_samples.to_i-1) do |j|
    data_list = []
    0.upto(@num_of_variables.to_i-1) do |i|
      eval "data_list +=[@#{@variables[2*i]}[j]]"
    end
    @out << data_list
  end
  @out.close

end


if __FILE__ == $0
  
  filename = ARGV[0]
  sl_to_csv filename
  
end
