#include "uart.h"

template <class T>
class dataStatistics
{
	private:
		T data[7];
		int capacity;
	
	public:
		dataStatistics();
	  dataStatistics(T d[]){
			for(int i=0;i<7;i++){
				
				data[i] = d[i];
			}
		}
		float computeMean();
		T findMax();
		int searchValue(T val);
		T findMode();
		
};

template <class T>
	
	float dataStatistics<T>::computeMean(){
		
		
	}

template <class T>
	T dataStatistics<T>::findMax(){
		T mx = data[0];
		for(int i=0;i<7;i++){
			
			if(mx < data[i])
				mx = data[i];
		}
		return mx;
	}
	
template <class T>
	T dataStatistics<T>::findMode(){
		
		
	}
	
template <class T>
	int dataStatistics<T>::searchValue(T val){
		
		
		
	}
int main()
{
	
	uart_init();
	
	float f_values[] = {0.1 , 0.2 , 0.9 , 0.8 , 0.11,0.34,0.78};
	int i_values[] = {7, 8 , 3 , 4 , 6 , 7 , 0};
	
	dataStatistics<float> f_dataset(f_values);
	dataStatistics<int> i_dataset(i_values);
	
	printf("The maximum value in dataset is %f \n\r",f_dataset.findMax());
	printf("The maximum value in dataset is %d \n\r",i_dataset.findMax());

	while(1){
		
		
	}
	
}
