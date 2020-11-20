rpn: rpn.c
	$(CC) -o $@ $< -lm

clean:
	rm rpn
