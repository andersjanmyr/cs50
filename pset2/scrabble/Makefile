
scrabble: scrabble.c
	cc -lcs50 $< -o $@

run: scrabble
	./scrabble

run-arg: scrabble
	./scrabble "Question?" "Question!"
	./scrabble "red" "weelbarrow"
	./scrabble "Scrabble" "wiNNeR"

clean:
	rm -f ./scrabble

