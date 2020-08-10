all:
	{ \
	cd ../; \
	git submodule init; \
	git submodule update; \
	cd tdd_creator/; \
	git submodule init; \
	git submodule update; \
	cd ../software/; \
	}
	./delete_comment ./inc/uart_data_transfer/uart_data_transfer_core.h
	./delete_comment ./inc/measurements/measurements_core.h
	./delete_comment ./inc/charger/charger_core.h
	make -f MakefileUnity.mk
	./insert_comment ./inc/uart_data_transfer/uart_data_transfer_core.h
	./insert_comment ./inc/measurements/measurements_core.h
	./insert_comment ./inc/charger/charger_core.h

clean:
	make -f MakefileUnity.mk clean

hardware:
	./insert_comment ./inc/uart_data_transfer/uart_data_transfer_core.h
	./insert_comment ./inc/measurements/measurements_core.h
	./insert_comment ./inc/charger/charger_core.h



