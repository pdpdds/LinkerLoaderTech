all :
	echo "% gcc hello.c -o hello -Wall -T hello.lds"  > hello.comp 2>&1
	gcc hello.c -o hello -Wall -T hello.lds          >> hello.comp 2>&1
	echo "% "                                        >> hello.comp 2>&1
	echo "% ./hello"                                  > hello.out  2>&1
	./hello                                          >> hello.out  2>&1
	echo "% "                                        >> hello.out  2>&1
	echo "% objdump -h -p hello"                      > hello.od   2>&1
	objdump -h -p hello                              >> hello.od   2>&1
	echo "% "                                        >> hello.od   2>&1
	#----------------------------------------------------------------------
	echo "% gcc addr.c -o addr -Wall -T addr.lds"     > addr.comp  2>&1
	gcc addr.c -o addr -Wall -T addr.lds             >> addr.comp  2>&1
	echo "% "                                        >> addr.comp  2>&1
	echo "% ./addr"                                   > addr.out   2>&1
	./addr                                           >> addr.out   2>&1
	echo "% "                                        >> addr.out   2>&1
	echo "% objdump -h -p addr"                       > addr.od    2>&1
	objdump -h -p addr                               >> addr.od    2>&1
	echo "% "                                        >> addr.od    2>&1
	#----------------------------------------------------------------------
	echo "% gcc conflict.c -o conflict -Wall -T addr.lds" > conflict.comp  2>&1
	gcc conflict.c -o conflict -Wall -T addr.lds     >> conflict.comp  2>&1
	echo "% "                                        >> conflict.comp  2>&1
	echo "% ./conflict"                               > conflict.out   2>&1
	./conflict                                       >> conflict.out   2>&1
	echo "% "                                        >> conflict.out   2>&1
	echo "% objdump -h -p conflict"                   > conflict.od    2>&1
	objdump -h -p conflict                           >> conflict.od    2>&1
	echo "% "                                        >> conflict.od    2>&1
	#----------------------------------------------------------------------
	echo "% gcc conflict.c -o provide -Wall -T provide.lds" > provide.comp  2>&1
	gcc conflict.c -o provide -Wall -T provide.lds   >> provide.comp  2>&1
	echo "% "                                        >> provide.comp  2>&1
	echo "% ./provide"                                > provide.out   2>&1
	./provide                                        >> provide.out   2>&1
	echo "% "                                        >> provide.out   2>&1
	echo "% objdump -h -p provide"                    > provide.od    2>&1
	objdump -h -p provide                            >> provide.od    2>&1
	echo "% "                                        >> provide.od    2>&1
	#----------------------------------------------------------------------

clean :
	rm -f *.comp *.out *.od
