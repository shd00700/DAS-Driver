add_executable(SLDD
        sldd.c
        sldd.h
        )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(SLDD
	pico_stdlib
        hardware_spi
        hardware_gpio
	)

# create map/bin/hex file etc.
pico_add_extra_outputs(SLDD)

# add url via pico_set_program_url
#example_auto_set_url(led)

