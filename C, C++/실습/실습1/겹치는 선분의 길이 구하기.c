#include <stdio.h>
int main(){
	float A_Left, A_Right;
	float B_Left, B_Right;
	float New_A_Left, New_A_Right;
	float New_B_Left, New_B_Right;
	float Overlap_Left, Overlap_Right;
	scanf("%f %f", &A_Left, &A_Right);
	scanf("%f %f", &B_Left, &B_Right);
	if(A_Left > B_Left){
		New_A_Left = B_Left;
		New_A_Right = B_Right;
		New_B_Left = A_Left;
		New_B_Right = A_Right;
	}
	else{
		New_A_Left = A_Left;
		New_A_Right = A_Right;
		New_B_Left = B_Left;
		New_B_Right = B_Right;
	}
	if(New_B_Left<=New_A_Right){
		Overlap_Left = New_B_Left;
		if(New_B_Right<=New_A_Right)
			Overlap_Right = New_B_Right;
		else
			Overlap_Right = New_A_Right;
	}
	else{
		Overlap_Right = -9999;
		Overlap_Left = -9999;
	}
	printf("%.2f", Overlap_Right - Overlap_Left);
}
