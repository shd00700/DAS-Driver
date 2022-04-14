add_executable(led
        led.c
        )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(led
	pico_stdlib
	)

# create map/bin/hex file etc.
pico_add_extra_outputs(led)

# add url via pico_set_program_url
#example_auto_set_url(led)

