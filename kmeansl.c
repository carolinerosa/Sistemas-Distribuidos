#include <stdio.h>
#include <mpi.h>
main(int argc, int** argv) {
	int my_rank;
	int p; // número de processos
	float pontos[][];
	int n=1024; // número de trapezóides
	float h; // base do trapezóide
	float local_a, local_b; // intervalo local
	int local_n; // número de trapezóides local
	float integral; // integral no meu intervalo
	float total; // integral total
	int source; // remetente da integral
	int dest=0; // destino das integrais (nó 0)
	int tag=200; // tipo de mensagem (único)
	
	
	
	MPI_Status status;
	
	int local_n, float h);
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &p);
	h = (b-a) / n;
	local_n = n / p;
	local_a = a + my_rank * local_n * h;
	local_b = local_a + local_n * h;
	if(my_rank == 0) {
		total = integral;
		for(source=1; source<p; source++) {
			MPI_Recv(&integral, 1, MPI_FLOAT, source, tag,
			MPI_COMM_WORLD, &status);
			total +=integral;
		}
	} else
		MPI_Send(&integral, 1, MPI_FLOAT, dest,
tag, MPI_COMM_WORLD);
	}
	if(my_rank == 0) printf("Resultado: %f\n"
		, total);
		MPI_Finalize();
	}
}

