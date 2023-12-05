#include <stdio.h>
#include <stdlib.h>
//μέσα στον κώδικα μου έχω χρησιμοποίησε συναρτήσεις όπως η sqrt(x) οπότε η χρήση της βιβλιοθήκης <math.h> είναι υποχρεωτική  
#include <math.h>
// έπειτα  όρισα τα όρια μου [1,10^15]
#define MAX pow(10,15)
#define MIN 1

//έθεσα την συνάρτηση prime η οποία εξετάζει αν ενας αριθμος n είναι πρώτος
 unsigned long long  prime(unsigned long long n){
//αρχικά ορίζουμε μια τοπική μεταβλητή j την οποία θα χρησιμοποιήσουμε αργότερα
 unsigned long long j;
//έπειτα εξετάζουμε αν είναι 2 επειδή είναι πρώτος και αποτελεί μια μικρή εξαίρεση στην τακτική μας 
    if(n==2) 
      return 1;
//εξετάζουμε αν το υπόλοιπο του της διαίρεσης του n με το 2 αν είναι 0  τότε δεν είναι πρώτος
    if(!(n%2)){
        return 0;
    }
//τέλος δημιουργούμε ένα loop στο οποίο το j ξεκινάει από το 3 μέχρι το ρίζα n καθώς n=x*y αν x>ρίζα n τότε y<ρίζα n 
//αλλιώς x*y>n το οποίο είναι άτοπο άρα αρκεί να ελέγξουμε όλες τις περιπτώσεις μέχρι ρίζα n
//και ανεβαίνει κατά 2(διότι ένας πρώτο αριθμός είναι και περιττος πέρα από το 2)
    for(j=3;j*j<=n;j+=2){
       if(!(n%j)){
         return 0;
       }
    }
// αν λοιπόν δεν διαιρείται με κανέναν από αυτούς του αριθμούς είναι πρώτος
    return 1;
}
//επίσης δημιούργησα την συνάρτηση mirror η οποία αντικατροπτίζει ένα αριθμό n
 long long  mirror(unsigned long long n){
//θα χρησιμοποιήσουμε 3 τοπικές μεταβλητές 
    unsigned long long k,c=0;// θα χρησιμοποιηθούν στο loop
    unsigned long long _n=0;//_n ανιπαριστά τον αντικατροπτισμένο αριθμό
    unsigned long long p=10;// θα μας βοηθήσει να βρούμε πότε σταματάμε το loop
//θα δημιουργήσουμε ένα μικρό βοηθητικό loop στο οποίο το p δεκαπλασιάζεται μέχρι το πηλίκο της ακέραιας διαίρεσης n/p να ισούται με n
    while(n%p!=n){
        p=p*10;
    }
//έτσι δημιουργώ ένα loop με την k να δεκαπλασιάζεται μέχρι να γίνει ίση με την p
//η c ανιπαριστά το ακέραιο πηλίκο της ακέραιας διαίρεσης 
    for(k=10;k<=p;k=k*10){
//για να δημιουργηθεί ο κατροπτικός αρκεί να προσθέτω κάθε φορά το  c  στο _n με το δεκαπλάσιο προηγούμενου _n
    c=n%10;
    _n=(_n*10)+c;
//όμως για να υλοποιηθεί σωστά πρέπει να υποδεκαπλασιάζω το n
//ουσιατηκά ξεκινάω να χτύζω τον αριθμό από απο αριστρ=ερά στα δεξιά βήμα βήμα
    n=n/10;
    }
    return _n;
}


int main(int argc, char**argv){
//αρχικά ορίζω τον αριθμό των ορισμάτων που επιθυμώ 
    if(argc !=3){
       return 1;
    }
//και ορίζω τις μεταβλητές που επιθυμώ από τον χρήστη δηλαδή το άνω και το κάτω όριο 
    unsigned long long low=atoll(argv[1]);
    unsigned long long high=atoll(argv[2]);
// ελέγχω αν τα όρια μου είναι εντός των ορίων [1,10^15] και αν το κάτω είναι όντως χαμηλότερο του άνω
   if(low>high || low<MIN || high>MAX){
         return 1;
  }
//εισάγω 3 μεταβλητές
 int sqlow=ceil(sqrt(low));//σε αυτήν αποθηκεύται η ρίζα του low όμως αν είναι δεκαδικός αποθηεύει τον επόμενο ακέραιο
 unsigned long long i;//είναι η βοηθητική μεταβλητή του loop
 unsigned long long sum=0;//είναι ο αθροιστής μας
  for(i=sqlow;i*i<=high;i++){
//ξεκινώντας από τον sqlow και τελειώνοντας πρακτικά στην ρίζα high και αυξάνω το i ένα σε κάθε επανάληψη
//κάνω τον αλγόριθμο δραστικά πιο γρήγορο καθώς δεν χρειάζεται να ελέγξω αν είναι τέλειο τεράγωνο καθώς παίρνω 
//απευθειάς το τετράγωνο ακεραίων j  που γνωρίζω ότι είναι 
    unsigned long long j=i*i;
//με το _j αναπαριστώ τον κατροπτικό του j
    unsigned long long _j=mirror(j);
    int _square=ceil(sqrt(_j));//χρησιμοποιώ αυτήν την μεταβλητή της ρίζας που παίρνει τον επόμενο μεγαλύτερο ακέραιο 
    // καθώς πρέπει να είναι ίδια με την ρίζα του _j για να είναι η ρίζα πρώτος και η συνάρτηση μας prime δεν απορρίπτει τους
    // δεκαδικούς οπότε το εξετάζουμε στο if μαζί με τους άλλους βασικούς παράγοντες καθώς πρέπει να τηρούνται όλες
    // οι προϋποθέσεις όπως ο j να μην είναι παλινδρομικός δηλαδή να μην ισούνται οι κατροπτικοί και να είναι και οι
    //δύο κατροπτικοί τέλεια τετράγωνα πρώτων 
    if(j!=_j && prime(i) && sqrt(_j)==_square && prime(_square)){
  // αν ισχύπυν όλες οι προϋποθέσεις προσθέτουμε το j στο άθροισμα 
           sum = sum + j;
    }  
 }
 //τέλος τυπώνουμε το άθροισμα μας 
 printf("%lld\n",sum);
 return 0;
} 
