#include<stdio.h>

int main(){
	int n;
	int choice;
	int arr[100];
	while(1){
		printf("\n--------MENU--------\n");
		printf("1.Nhap so phan tu va gia tri cho mang\n");
		printf("2.In ra cac phan tu trong mang\n");
		printf("3.So luong cac so hoan hao\n");
		printf("4.So luong cac so nguyen to\n");
		printf("5.Gia tri lon thu 2 trong mang\n");
		printf("6.Gia tri nho thu 2 trong mang\n");
		printf("7.Them mot phan tu vao trong mang\n");
		printf("8.Xoa phan tu trong mang\n");
		printf("9.Sap xep mang theo thu tu tang dan\n");
		printf("10.Sap xep mang theo thu tu giam dan\n");
		printf("11.Tim kiem phan tu\n");
		printf("12. Xoa phan tu trung lap va in phan tu doc nhat\n");
		printf("13.Sap xep lai mang va hien thi\n");
		printf("14.Dao nguoc thu tu cua cac phan tu co trong mang\n");
		printf("15.Thoat\n");
		printf("Lua chon chua ban: ");
		scanf("%d", &choice);
		
		if (choice==15){
			printf("Ket thuc chuong trinh\n");
			break;
		}
		
		switch(choice){
		    case 1:
			    printf("Nhap so phan tu cua mang: ");
				scanf("%d", &n);
				for(int i=0;i<n;i++){
					printf("Nhap phan tu thu %d: ", i+1);
					scanf("%d", &arr[i]);
				}
				break;
			case 2:
				printf("Cac phan tu trong mang la:\n");
			    for(int i=0;i<n;i++){
			    	printf("Phan tu arr[%d] = %d",i,arr[i]);
			    	printf("\n");
				}
				break;
			case 3:{
				int count=0;
	            for (int i=0;i<n;++i){
	                int sum=1;
	                for(int j=2;j*j<=arr[i];++j){
	                    if(arr[i]%j==0){
	                        sum+=j;
	                        if(!(arr[i]/j==j))
	                            sum+=arr[i]/j;
	                    }
	                }
	                if (sum==arr[i]&&arr[i]>=6){
							count++;
							printf("%d\n",arr[i]);
						}
	            }
	            printf("So luong so hoan hao: %d", count);
		        break;
		    }
			case 4:{
				int count=0;
	        	for(int i=0;i<n;++i){
	        		int prime=0;
	        		for(int j=2;j*j<=arr[i];++j){
	        			if (arr[i]%j==0){
	        				prime =1;
	        				break;
						}
					}
					if(!prime && arr[i]>=2){
						++count;
					}
				}
				printf("So luong cac phan tu la so nguyen to trong mang: %d", count);
	        	break;
			}
			case 5:
				int max1 ;
			    int max2 ;
			    max1=arr[0];
			    max2=-1;
			    for (int i=1;i<n;i++) {
			        if (arr[i]>max1) {
			            max1=arr[i];
			        }
			    }
			
			    for (int i=0;i<n;i++) {
			        if (arr[i]!=max1) {
			            if (max2==-1||arr[i]>max2) {
			                max2=arr[i];
			            }
			        }
			    }
			    printf("Gia tri lon thu 2 trong mang la: %d", max2);
				break;	
			case 6:
				int min1 ;
			    int min2 ;
			    min1=arr[0];
			    min2=0;
			    for (int i=1;i<n;i++) {
			        if (arr[i]<min1) {
			            min1=arr[i];
			        }
			    }
			
			    for (int i=0;i<n;i++) {
			        if (arr[i]!=min1) {
			            if (min2==0||arr[i]<min2) {
			                min2=arr[i];
			            }
			        }
			    }
			    printf("Gia tri nho thu 2 trong mang la: %d", min2);
				break;	
			case 7:
				int newValue;
				int position;
				printf("Nhap phan tu muon them vao: ");
				scanf("%d", &newValue);
				printf("Nhap vi tri muon them (0 - %d): ",n-1);
				scanf("%d", &position);
				if(position<0||position>=n){
					printf("Vi tri vua nhap khong hop le!");
					break;
				}
				for(int i=n;i>position;i--){
					arr[i]=arr[i-1];
				}
				arr[position]= newValue;
				n++;
				break;	
			case 8:
			    int deletePosition;
				printf("Nhap vi tri phan tu muon xoa (0 - %d): ", n-1);
				scanf("%d", &deletePosition);
				if(deletePosition<0||deletePosition>=n){
					printf("Vi tri khong hop le!");
					break;
				}
				for(int i=deletePosition;i<n;i++){
					arr[i]=arr[i+1];
				}
				n--;
				break;
			case 9:
			    for(int i=1;i<n;i++){
			    	int key=arr[i];
			    	int j=i-1;
			    	while(j>=0&&arr[j]>key){
			    		arr[j+1]=arr[j];
			    		j=j-1;
					}
					arr[j+1]=key;
				}
				printf("Mang sau khi duoc sap xep: ");
				for(int i=0;i<n;i++){
					printf("%d\t",arr[i]);
				}	
				break;
			case 10:
				for(int i=1;i<n;i++){
			    	int key=arr[i];
			    	int j=i-1;
			    	while(j>=0&&arr[j]<key){
			    		arr[j+1]=arr[j];
			    		j=j-1;
					}
					arr[j+1]=key;
				}
				printf("Mang sau khi duoc sap xep: ");
				for(int i=0;i<n;i++){
					printf("%d\t",arr[i]);
				}	
				break;
			case 11:{
				int findValue;
				int left=0;
				int right=n-1;
				int found=-1;
				printf("Moi ban nhap phan tu can tim: ");
				scanf("%d", &findValue);
				while (left<=right) {
			    	int mid=left+(right-left)/2;
			        if (arr[mid]==findValue) {
			            found=mid;
			            break;
			        } else if (arr[mid]<findValue) {
			            left=mid+1;
			        } else {
			            right=mid-1;
			        }
			    }
			    if (found!=-1) {
			        printf("Phan tu %d duoc tim thay tai vi tri thu %d\n", findValue, found);
			    } else {
			        printf("Phan tu %d khong co trong mang\n", findValue);
			    }
				break;
			}
			case 12:
				for (int i=0; i<n; i++){
					for (int j=i+1; j<n; j++){
						if(arr[i]==arr[j]){
							for (int deleteNumb=j;deleteNumb<n-1;deleteNumb++){
							  arr[deleteNumb] = arr[deleteNumb + 1]; 
							}
							n--;
							j--;
						}
					}
				}
				printf("Mang sau khi xoa cac phan tu trung lap: ");
				for (int i=0; i<n; i++){
					printf ("%d ",arr[i]);
			    }
			    printf ("\n");	
			    break;
			case 13:
				for(int i=0;i<n-1;i++){
			        for(int j=i+1;j<n;j++) {
			        	int temp;
			            if ((arr[i]%2!=0)&&(arr[j]%2==0)){
			                temp = arr[i];
			                arr[i] = arr[j];
			                arr[j] = temp;
			            }
			        }
			    }
			    printf("Mang sau khi sap xep: ");
			    for (int i=0;i<n;i++) {
			        printf("%d ", arr[i]);
			    }
			    printf("\n");
			    break;
			case 14:
			    for (int i = 0; i < n / 2; i++) {
			        int temp = arr[i];
			        arr[i] = arr[n - i - 1];
			        arr[n - i - 1] = temp;
			    }
			    printf("Mang sau khi dao nguoc: ");
			    for (int i = 0; i < n; i++) {
			        printf("%d ", arr[i]);
			    }
			    printf("\n");	
			    break;
			default:
			   printf("Lua chon khong hop le!");
			   break;	
		}
	}
	return 0;
}
