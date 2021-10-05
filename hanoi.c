#include <stdio.h>
#define N 4

int tab_disks[N] = {1};

void display_table(){
	for(int k = 0; k < N; k++){
		printf("%d ", tab_disks[k]);
	}
	printf("\n");
}

void disp_disks(){
	int G = 2*N-1;
	char tige_1[N][2*N] = {};
	char tige_2[N][2*N] = {};
	char tige_3[N][2*N] = {};
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	int size1 = 0, size2 = 0, size3 = 0;

	// Calcul du nombre de disques à dessiner par tige
	for(int k = 0; k < N; k++){
		if(tab_disks[k] == 1) //tige 1
			cnt1++;
		if(tab_disks[k] == 2) //tige 2
			cnt2++;
		if(tab_disks[k] == 3) //tige 3
			cnt3++;
	}

	// Remplissage des lignes vides par tige
	//tige 1
	for(int k = 0; k < N; k++){
		for(int c = 0; c < G; c++){
			tige_1[k][c] = ' ';
		}
	}
	//tige 2
	for(int k = 0; k < N; k++){
		for(int c = 0; c < G; c++){
			tige_2[k][c] = ' ';
		}
	}
	//tige 3
	for(int k = 0; k < N; k++){
		for(int c = 0; c < G; c++){
			tige_3[k][c] = ' ';
		}
	}

	//Remplissage des cases comportant un disque par case
	//tige 1
	for(int k = 0; k < N; k++){
		if(tab_disks[k] == 1){
			size1 = 2*k+1;
			for(int c = (G-size1)/2; c < G-(G-size1)/2; c++){
				tige_1[N-cnt1][c] = '='; 
			}
			cnt1--;
		}
		if(tab_disks[k] == 2){
			size2 = 2*k+1;
			for(int c = (G-size2)/2; c < G-(G-size2)/2;c++){
				tige_2[N-cnt2][c] = '='; 
			}
			cnt2--;
		}
		if(tab_disks[k] == 3){
			size3 = 2*k+1;
			for(int c = (G-size3)/2; c < G-(G-size3)/2;c++){
				tige_3[N-cnt3][c] = '='; 
			}
			cnt3--;
		}
	}
	//affichage
	for(int i = 0; i < N; i++){
		printf("\t%s\t%s\t%s\n", tige_1[i], tige_2[i], tige_3[i]);
	}
}

void move(int n, int t_start, int t_end){
	printf("\n\nDeplacement du disque %d de la tige %d vers la tige %d\n\n", n, t_start, t_end);
	tab_disks[n-1] = t_end;
	disp_disks();
}

int hanoi(int n, int t_left, int t_middle, int t_right){
	if(n == 1){
		move(1, t_left, t_right);
		//disp_disks();
	}
	else{

		hanoi(n-1, t_left, t_right, t_middle);
		move(n, t_left, t_right);
		//disp_disks();
		hanoi(n-1, t_middle, t_left, t_right);
	}
}

int main(void){
	disp_disks();
	hanoi(N, 1, 2, 3);

}