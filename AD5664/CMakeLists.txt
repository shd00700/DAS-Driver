add_executable(AD5664
        AD5664.c
        )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(AD5664
	pico_stdlib
	)

# create map/bin/hex file etc.
pico_add_extra_outputs(AD5664)

# add url via pico_set_program_url
#example_auto_set_url(led)

