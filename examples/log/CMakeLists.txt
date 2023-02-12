function(
	add_fcppt_log_example
	EXAMPLE_NAME
)
	message("MV: TMP: ${fcppt_core_TARGET}")
	message("MV: TMP: ${fcppt_log_TARGET}")
	add_fcppt_example(
		log/${EXAMPLE_NAME}
		LINK_LIBS
			${fcppt_core_TARGET}
			${fcppt_log_TARGET}
	)
endfunction()

add_fcppt_log_example(
	context
)

add_fcppt_log_example(
	formatting
)

add_fcppt_log_example(
	helloworld
)
