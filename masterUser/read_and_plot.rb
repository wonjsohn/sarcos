#!/usr/bin/ruby
# convert binary-encoded SL log files to .CSV, then plot them


def read_and_plot(filename)

  @filename = filename
  puts "Converting #{@filename} to .CSV"
  system("ruby read_sl_data.rb #{@filename}")
  
  puts "Plotting #{@filename}.csv"
  system("python csv_to_plot.py #{@filename}.csv")



end



if __FILE__ == $0

  filename = ARGV[0]
  read_and_plot filename

end
