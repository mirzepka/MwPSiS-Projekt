all:
	g++ solver.cpp -o solve_gmpl -L/usr/local/lib -lClpSolver -lClp -lreadline -lncurses -lCoinUtils -lreadline -lncurses -lbz2 -lz -llapack -lblas -lm -lcoinglpk -ldl -lm -lgmp
	g++ -o cgi cgi.cpp /usr/lib/libcgicc.a
	sudo cp cgi /usr/lib/cgi-bin

clean:
	rm solve_gmpl cgi
