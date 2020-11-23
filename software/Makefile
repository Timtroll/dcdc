all:
	git submodule update --init --recursive
	make -f MakefileUnity.mk

clean:
	make -f MakefileUnity.mk clean

hardware:
	./insert_comment ./inc/uart_data_transfer/uart_data_transfer_core.h
	./insert_comment ./inc/measurements/measurements_core.h
	./insert_comment ./inc/charger/charger_core.h



