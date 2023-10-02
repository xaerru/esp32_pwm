current_dir = $(shell pwd)

all: compile upload

setup:
	sudo chmod a+rw /dev/ttyUSB0

compile: setup
	arduino-cli compile --fqbn esp32:esp32:esp32da $(current_dir)

upload:
	arduino-cli upload -p /dev/ttyUSB0 --fqbn esp32:esp32:esp32da $(current_dir)

monitor: setup
	arduino-cli monitor -p /dev/ttyUSB0

plot:
	nohup serialplot > /dev/null 2>&1 &

ide: setup
	nohup arduino-ide $(current_dir) > /dev/null 2>&1 &
