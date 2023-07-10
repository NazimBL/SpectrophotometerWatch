import serial
import csv


serial_port = 'COM13'  # Update with the correct port

baud_rate = 115200
ser = serial.Serial(serial_port, baud_rate)

# change the CSV file name each experiment to save the data
csv_file = open('sensor_data.csv', 'w', newline='')
csv_writer = csv.writer(csv_file)

# Header
header = ['410nm', '435nm', '460nm', '485nm', '510nm', '535nm', '560nm', '585nm', '610nm', '645nm', '680nm', '705nm', '730nm', '760nm', '810nm', '860nm', '900nm', '940nm']
csv_writer.writerow(header)

# Read and save the data from the watch
try:
    while True:
        line = ser.readline().decode().strip()  # Read a line of data from the serial connection

        if line:  # If the line is not empty
            data = line.split(',')
            csv_writer.writerow(data)
            print(data)  # Print the data to the console

except KeyboardInterrupt:
    pass

# Close the CSV file and serial connection
csv_file.close()
ser.close()
