bs:
	gcc -o s generated-code.c server.c `pkg-config --cflags --libs  gio-unix-2.0`

bc:
	gcc -o c generated-code.c client.c `pkg-config --cflags --libs  gio-unix-2.0`

gen:
	gdbus-codegen --interface my.namespace  --generate-c-code generated-code --c-namespace example  a.xml

clean:
	rm -rf s c
	rm -rf generated-code.c generated-code.h
