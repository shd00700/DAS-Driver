add_executable(AD5664
        AD56x4.c
        AD56x4.h
        main.c
        )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(AD5664
	pico_stdlib
    hardware_spi
	)

# create map/bin/hex file etc.
pico_add_extra_outputs(AD5664)

# add url via pico_set_program_url
#example_auto_set_url(led)

