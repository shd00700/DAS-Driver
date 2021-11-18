add_executable(Optical-SW
        optical-sw.c
        )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(Optical-SW
	pico_stdlib
	)

# create map/bin/hex file etc.
pico_add_extra_outputs(Optical-SW)

# add url via pico_set_program_url
#example_auto_set_url(led)

