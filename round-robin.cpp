#include<bits/stdc++.h>
using namespace std;
struct Process {
   int pid; // ID proces
   int bt; // CPU Burst time required
   int priority; // Prioritatea acestui proces
};
// sortarea procesului acc. la prioritate
bool compare(Process a, Process b) {
   return (a.priority > b.priority);
}
void waitingtime(Process pro[], int n, int wt[]) {
   // Timpul inițial de așteptare pentru un proces este 0
   wt[0] = 0;
   // timp de asteptare calculat
   for (int i = 1; i < n ; i++ )
      wt[i] = pro[i-1].bt + wt[i-1] ;
}
 // Funcție pentru a calcula timpul de rotație
void turnarround( Process pro[], int n, int wt[], int tat[]) {
   // calcularea timpului de răspuns prin adăugare
   // bt[i] + wt[i]
   for (int i = 0; i < n ; i++)
      tat[i] = pro[i].bt + wt[i];
}
//Funcție pentru a calcula timpul mediu
void avgtime(Process pro[], int n) {
   int wt[n], tat[n], total_wt = 0, total_tat = 0;
   //Funcție pentru a găsi timpul de așteptare al tuturor proceselor
   waitingtime(pro, n, wt);
   //Funcție pentru a găsi timpul de rotație pentru toate procesele
   turnarround(pro, n, wt, tat);
   //Afișați procesele împreună cu toate detaliile
   cout << "\nProcesses "<< " Burst time " << " Waiting time " << " Turn around time\n";
   // Calculați timpul total de așteptare și rotația totală
   // around time
   for (int i=0; i<n; i++) {
      total_wt = total_wt + wt[i];
      total_tat = total_tat + tat[i];
      cout << " " << pro[i].pid << "\t\t" << pro[i].bt << "\t " << wt[i] << "\t\t " << tat[i] <<endl;
   }
   cout << "\nTimp mediu asteptare = " << (float)total_wt / (float)n;
   cout << "\nTimp mediu rotatie = " << (float)total_tat / (float)n;
}
void scheduling(Process pro[], int n) {
   // Sort processes by priority
   sort(pro, pro + n, compare);
   cout<< "Ordinea proceselor in executare \n";
   for (int i = 0 ; i < n; i++)
      cout << pro[i].pid <<" " ;
   avgtime(pro, n);
}

int main() {
   Process pro[] = {{1, 10, 2}, {2, 5, 0}, {3, 8, 1}};
   int n = sizeof pro / sizeof pro[0];
   scheduling(pro, n);
   return 0;
}
