#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void kabakuvvet(int array[], int size){
  int min = abs(array[0] + array[1]);
  for(int i = 0; i < size; i++){
    for(int j = i + 1; j <= size; j++){
      if(abs(array[i] + array[j]) < min)
        min = abs(array[i] + array[j]);
    }
  }
  for(int i = 0; i < size; i++){
    for(int j = i + 1; j <= size; j++){
      if(abs(array[i] + array[j]) == min)
        printf("%d + %d = %d\n", array[i], array[j], array[i] + array[j]);
    }
  }
}

int main(){
  //int array[] = {24,-180,-403,302,-255,745,252,683,-483,-796,-526,-524,323,594,-628,329,-185,-84,551,-938,-276,795,872,227,-334,-247,-963,273,-216,-458,-44,374,-589,170,-157,-479,-29,259,-573,356,-601,985,-789,-647,-416,84,9,495,-464,968,937,220,664,663,155,-142,-976,-504,570,524,-788,-32,-168,149,179,-764,-376,-327,103,134,387,486,-141,797,-792,294,-494,-253,-448,-46,-205,386,-530,12,86,-721,532,-68,-560,-471,626,-477,-696,-964,-694,737,-835,963,238,980,-12,720,-784,553,655,22,244,-88,-153,-411,514,328,379,-869,-487,346,177,-667,646,-617,-918,-877,368,-677,-23,667,-503,-428,-724,-950,-410,-731,933,-612,397,137,563,-540,202,-315,-478,670,-362,-857,417,-770,287,-684,-979,789,-288,-202,541,-172,-927,279,763,60,380,-550,-794,-829,-62,-495,661,660,965,-988,-785,-366,-513,-754,373,-552,-897,213,989,658,-179,85,-300,-397,624,-921,133,100,57,-587,-4,815,969,-158,343,-809,928,-10,-194,-261,-212,878,-252,-277,-584,488,208,315,-434,-807,-822,863,-2,916,101,111,296,10,-490,14,-973,361,-355,935,-888,764,601,623,-370,-871,-804,456,-676,616,-522,992,666,-81,-109,931,-76,312,-390,209,64,733,-445,232,-881,224,907,-144,-917,-293,843,925,864,-896,463,-968,-167,468,978,-733,424,-644,702,-320,-837,311,-558,874,-625,-70,529,-413,890,975,-7,-451,462,261,-914,-760,-186,-245,-743,705,-459,929,-980,-457,743,645,48,715,-3,-287,49,-435,-496,962,-468,-960,-93,504,-942,-378,-108,47,-130,-750,-87,-581,993,214,-571,-817,-635,210,338,-412,70,-703,175,-748,349,389,798,378,-197,409,28,454,841,862,901,458,782,657,235,-358,251,-566,-996,771,-56,-834,-431,-521,-853,-799,325,-381,6,-231,-225,-671,861,831,503,310,854,229,411,762,586,-565,-554,-332,390,-454,-83,-778,-751,-91,-588,708,678,934,-34,-971,90,-294,-860,-758,-883,-556,-987,-47,-103,538,-336,-606,672,-266,680,-875,-531,99,956,-38,-275,-660,67,-424,358,-350,-810,479,221,883,-339,-669,610,489,-389,-444,-388,970,681,490,751,467,351,450,-958,-833,911,921,-25,-935,-711,119,-299,370,-954,-978,-163,-736,-782,-949,413,530,-783,-52,581,187,-256,946,-909,264,383,-249,-356,476,-923,991,148,321,377,600,-899,-891,-295,-870,-283,767,-24,-508,-675,-48,665,347,-37,736,401,957,-437,-928,432,722,-329,-672,475,615,-94,276,-166,573,-772,-420,-65,-905,-465,292,-827,91,621,297,-517,-204,889,414,686,258,-709,-816,290,200,113,-777,749,627,927,796,-500,484,697,-439,-257,492,-169,567,440,205,865,-692,-51,-532,903,295,823,-98,-115,-407,-854,-761,-583,987,-668,407,249,480,-910,-962,145,-60,-535,-936,917,-367,-604,222,845,126,500,-720,191,-461,-178,-347,-117,-982,867,966,791,482,107,-323,746,554,87,-756,-386,427,-114,459,986,-27,426,263,511,-425,337,577,-274,250,-482,-723,-969,959,-795,-941,-595,932,802,-929,-273,219,-882,591,785,846,-338,-36,807,212,-152,-31,938,-767,583,447,171,834,98,636,-755,15,-312,-544,-372,983,400,930,-290,-50,266,873,742,-251,131,-945,298,388,-421,-132,-666,644,-643,-582,-702,-161,-577,-984,-952,520,943,533,-452,820,909,-380,-623,339,23,617,-825,920,857,-423,-641,335,632,835,-555,477,217,682,574,750,-173,940,838,-41,-576,-547,-243,885,-140,-848,470,832,-970,855,-673,88,-67,493,981,-333,-395,255,808,-808,385,-811,-291,-511,-432,236,-840,875,-874,-363,327,240,369,21,-726,-8,-863,406,116,-908,-392,741,-384,367,765,-608,534,-913,-364,547,-663,593,154,193,-793,-136,519,-868,914,869,71,976,-360,891,-322,308,-515,780,-418,759,-850,44,141,898,-944,-771,408,-630,-940,-859,584,-734,336,457,-415,437,271,-634,97,-264,710,-328,-466,-678,130,-233,773,-773,536,-135,-131,545,518,673,8,188,-607,180,194,-460,-201,-590,-545,839,787,564,62,-814,-208,588,443,-215,-598,17,-236,-351,-934,165,56,-16,195,13,-262,-191,146,847,786,-19,-633,-915,-124,-223,-240,423,446,-89,412,735,-867,-843,-911,104,961,-146,-453,-746,345,316,-85,-943,122,-414,691,-716,-260,706,-42,-456,-447,52,-99,859,734,971,-419,-775,837,-181,-14,-622,494,-165,-311,-985,540,-463,738,257,984,156,-693,-126,-149,535,-190,-298,26,-45,-717,-96,270,-133,-100,-382,821,-265,-690,884,-450,830,777,996,-599,33,396,753,-310,790,772,-184,192,268,72,-481,-472,-211,651,649,-986,-66,499,-831,117,-219,167,435,277,-542,913,-818,-486,-278,132,510,537,592,-78,625,55,198,799,522,-681,-714,-997,415,-626,157,-505,299,725,-994,605,282,184,505,779,900,827,801,-306,902,881,955,950,-640,464,364,135,688,-227,421,-803,-959,425,461,654,-706,-821,-269,690,139,760,469,788,501,-646,-757,851,-9,703,-865,306,-806,936,-160,-156,196,313,-820,-538,754,531,768,-753,-989,151,825,-79,894,-602,711,-737,-387,766,35};
  int array[] = {15, -14, 28, -29, 0, 1};
  int size = sizeof(array)/sizeof(array[0]);

  double time_spent = 0.0;
  clock_t begin = clock();

  kabakuvvet(array, size);

  clock_t end = clock();
  time_spent += (double)(end - begin);
  printf("\n%f ms", time_spent);
}
