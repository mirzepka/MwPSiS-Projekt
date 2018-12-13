/* -------------------------------------------------------------------------
 * MPSiS 2018/2019, L1
 * An example application solving an LP problem defined in an external GMPL file
 * A. Kamisiński
 *
 * Build:
 *  g++ solver.cpp -o solve_gmpl -lClp -lCoinUtils
 * -------------------------------------------------------------------------
*/

#include <stdio.h>
#include <coin/ClpSimplex.hpp>
#include <coin/CoinUtilsConfig.h>

int main( int argc, char *argv[] )
{
	ClpSimplex model;
	int status;

	if ( argc < 2 )
	{
		//printf( "Usage: ./solve_gmpl <gmpl-model-file> [ <gmpl-data-file> ]\n" );

		return 1;
	}

	if ( argc == 2 )
	{
		status = model.readGMPL( argv[ 1 ], NULL );
	}
	else
	{
		status = model.readGMPL( argv[ 1 ], argv[ 2 ] );
	}
	
	if ( status != 0 )
	{
		//printf( "E: Failed to load the model and data files\n" );
		
		return 1;
	}
	
	model.setLogLevel( 2 );
	status = model.primal();
	//printf( "----------------------------------------\n" );

	int iterations_count = model.numberIterations();
	//printf( "Model status after %d iterations: %d (0: optimal, 1: primal infeasible, 2: dual infeasible, 3: stopped on iterations, 4: stopped due to errors)\n", iterations_count, status );

	if ( model.primalFeasible() == false )
	{
		printf( "FINAL_LOG:PRIMAL INFEASIBLE!\n" );
		
		return 0;
	}
	
	printf( "FINAL_LOG:PRIMAL FEASIBLE! Objective value = %g\n", model.objectiveValue() );

	int rows_count = model.numberRows();
	int columns_count = model.numberColumns();
	
	//printf( "The model has %d rows and %d columns.\n", rows_count, columns_count );
	
	double *column_primal = model.primalColumnSolution();
	int i;

	for ( i = 0; i < columns_count; ++i )
	{
		if(i == 0)
			printf("FINAL_LOG:Reqular Tickets:\n");
		if(i == (columns_count/2))
			printf("FINAL_LOG:Premium Tickets:\n");
    if ((int)column_primal[ i ] != 0)
		  printf( "FINAL_LOG:e[%d] = %d\n", (i + 1)%(columns_count/2+1), (int)column_primal[ i ] );
	}
//	for ( i = 0; i < columns_count; ++i )
//	{
//		printf( "y[%d] = %g\n", i + 1, column_primal[ i ] );
//	}

	return 0;
}
