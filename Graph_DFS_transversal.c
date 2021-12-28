#include <stdio.h>
#include <stdlib.h>

/* Dekho, 5 min mai apan smjhte h ki DFS hota kya h, toh DFS kuch nai re bs ek simple sa transversal h,

|
|                                    # Assume ki ye 6 rahya h aur apan ko sb jeetna h
|              0 -- 5
|              |  \ | \
|              4 -- 1--3
|              |
|              2

 # Let's take a walk from one point to another and haath mai ek register le lo, aur usme jis bhi point kr pahuche
   likhte jao, but han agar same point pr firse jaana avoid krna.(aur han bhaiya, firse likhna bhi nai)

Ab, ye ek simple sa graph le lo, aur koi bhi ek node pakad lo, lets take 0, ab ye batao ki 0 se kaha kaha ja skte h?
1, 4, 5 na ? toh chalo vese hi chalte h, pr jaisa ki apne bharat mai hamesa hota h toh chote se bade chalte h
(bakki kahi bhi ja skte ho tum, but fir code khud hi likhna)

toh chalo 0 se 1 chalte aur baaki 3 raste discover krne pending rakhte h. Chalo toh ab apan pahuch gaye 1 pe,
ab kya? ab yaha se apan 0, 3, 4, 5 ja skte h, aur chota toh 0 h but bete register mai dekho, 0 toh jeet aaye apan
toh next chota h 3, toh chalo chalte h. Ab apan ne 3 bhi jeet liya, toh likh lo register mai fir. pr ab 3 se kaha
jaaye? 1, 5 ja skte h but 1 toh jeet chuke h toh 5 chalte h. Ab apan ne 5 bhi jeet liya, ab? yaha se toh 3 hi raste h
0, 1, 3 aur kisi mai toh jaana padega. But apne compiler babu ka ego thoda bada h toh vo bolte h ki jo jeet chuka
vaha toh nai jaunga toh vo gaadi reverse lene lagte h. toh yaha se jayega vapas 3 mai aur check karega ki koi undiscovered
route h kya? but yaha bhi 1 and 5 jeet chuke h toh fir reverse le ke 1 pe jayega aur check karega ki last time
3 pe chale gaye the but 4 jaane ka bhi toh raasta h and undiscovered bhi h toh 4 chala jayega aur jeet lega.
Ab 4 se do raste h, 1, 2. 1 toh jeet chuke h aur 2 bacha h toh chalo vo bhi jeet lete h. ab toh ek hi rasta bacha h
wapas 4 ka toh waha hi jana padega. ACHAA EK CHEEZ NOTICE KARO APAN NE TOH SAARE RAJYA JEET LIYE TOH AB KYA?

Kuch nai comipler baabu reverse lagana chalu karenge aur check krte rahege hi raste mai voi sa route undiscovered na
rehjaaye.
toh 2 se 4, 4 se 1, aur 1 se wapas 0 aur ho gaya.


Bs Bs Bs......Bs yahi krna h code mai bhi aur code mai kisi raste mai jaane ke liye recursion ka use karenge.

toh chalo krte h...

Accha kya is kahani se apan compiler ko smjha skte h? nai na toh basically ye kaam compiler kaise krta h sun lo,
YAhi cheez karega same bs krta kaise h ye dekh lo aur han tum ko manually bhi nikaalna pade toh tum bhi aisa krna.

Dekho, ab poora khel bs stack ka h, toh ek stack le lo. Aur koi bhi ek node pakad lo.

pehle iss node ko stack daaldo. 
Ab suno, JO BHI ELEMENT STACK SE POP KAROGE, USKE CONNECTED NODES DEKHO aur agar vo 
nodes VISITED LIST MAI NA ho toh usko STACK MAI PUSH karoge. ok? VO ELEMENT POP HOGA SIRF VO VISITED MAI JAYEAGA.

Ab kyoki ye kaam jo element pop hua h uspe hota h toh zero ko daalo stack mai aur pop kr lo, ab pop kia toh 
kaam chaalu karo, visited mai 0 daalo and stack mai uske conneccted nodes i.e . 1, 4, 5 push karo.
Ab dekho, vese toh tum kisi bhi order mai daal skte ho but kyoki is code mai apan ascending rakhenge toh stack mai 
desending order ami daalo mtlb pehle 5, fir 4 aur fir 1 taaki pop ascending order mai ho. ab top element i.e. 1 ko 
pop kr ke visited mai daalo and auke connected nodes ko bhi isi pattern mai stack mai daal do. 
YAAD RAKHNA, AGAR KOI ELEMENT VISITED MAI H TOH USKO STACK MAI MT DAALNA.
nai smjhe toh neeche dekho re

Diagram dekh ke stack dekho, aa jayega smjh

stack S:   
        |______|
        |__5___|  --> 4th pop : 5 
        |__3___|  --> 3rd pop : 3
        |__4___|  --> 5th pop : 4 (iske baad 2 push hoga and fir vo bhi pop hpo jayega fir since saare nodes visited mai aa jayenge toh bs pop hota rahega jb tk stack empty na ho)
        |__5___|
        |__1___|  --> 2nd pop : 1
        |__4___|
        |__5___|
        |__0___|  --> 1st pop : 0




*/

const int V = 6; // No. of vertices: Change it when needed, But you can only change it here, not in runtime

// We could have created visited locally in DFS but then we would need to create a new function for recurssion, henve
// creating it globally.

int visited[6] = {0, 0, 0, 0, 0, 0}; // We could have used calloc to initite with zero in heap memory(ye apna register)

void init(int arr[][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            arr[i][j] = 0; // Initiating every value with 0
        }
    }
}

void addEdge(int arr[][V], int src, int des)
{
    arr[src][des] = 1;
    // For undirected
    arr[des][src] = 1;
}

// Dekho, yaad h na ki recurssion mai functions ek ke uper ek stack ho jaate h and execute hote h, toh bs vahi ye use kr ra h.
void DFS(int arr[][V], int start)
{ 
     
    visited[start] = 1; // Pehle node jeet ke register mai mark lagaya
    printf("%d, ", start);
    for (int i = 0; i < V; i++) // 0 se 5 tk checking hogi(asending mai)
    {
        if (arr[start][i] == 1 && visited[i] != 1) // condition1: Route h bhi ki nai start se i tk ka
        {                                          // condition2: Pehle se discovered(jeeta hua) toh nai h node
            DFS(arr, i);                           // dono true h toh ghus jaao route mai
        }
    }
}

// void DFS_mainloop(){}  YE na krna pade isiliye visited ko global bana diya
void printGraph(int arr[][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d ", arr[i][j]);
        }
        /* code */
        printf("\n");
    }
}

int main()
{
    // int graph[6][6] =         // Aise bhi bana skte h graph toh but apan kyo dimaag lagao faltu, let computer do it
    //     {{0, 1, 0, 0, 1, 1},  //
    //      {1, 0, 0, 1, 1, 1},  //           0 -- 5
    //      {0, 0, 0, 0, 1, 0},  //           |  \ | \      
    //      {0, 1, 0, 0, 0, 1},  //           4 -- 1--3
    //      {1, 1, 1, 0, 0, 0},  //           |
    //      {1, 1, 0, 1, 0, 0}}; //           2

    int graph[6][6];

    init(graph); // Bs ye krna padta h, liken fir errors nai aati

    addEdge(graph, 0, 1); // Galtiya nai hoti h aise mai
    addEdge(graph, 0, 4);
    addEdge(graph, 0, 5);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 5);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);

    printGraph(graph);

    printf("DFS Transversal: ");

    DFS(graph, 0);

    return 0;
}