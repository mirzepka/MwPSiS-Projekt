all:
	g++ solver.cpp -o solve_gmpl -L/usr/local/lib -lClpSolver -lClp -lreadline -lncurses -lCoinUtils -lreadline -lncurses -lbz2 -lz -llapack -lblas -lm -lcoinglpk -ldl -lm -lgmp
clean:
	rm solve_gmpl
