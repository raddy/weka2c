#include <iostream>

using namespace std;

string classify(string seed, string int-discolor, string leaf-malf, string shriveling, string severity, string seed-discolor, string fruiting-bodies, string canker-lesion, string stem-cankers, string leaf-mild, string leafspots-marg, string leafspot-size, string leafspots-halo, string leaf-shread, string fruit-spots, string stem, string date, string germination, string plant-growth, string temp, string seed-tmt, string precip, string fruit-pods){

  if((leaf-malf=="present") && (stem=="abnorm"))
    return "herbicide-injury";
  if((fruit-pods=="few-present"))
    return "cyst-nematode";
  if((shriveling=="present") && (stem-cankers=="absent"))
    return "diaporthe-pod-";
  if((leaf-malf=="present") && (leafspots-halo=="absent"))
    return "2-4-d-injury";
  if((leaf-mild=="upper-surf"))
    return "powdery-mildew";
  if((seed-discolor=="present") && (canker-lesion=="tan"))
    return "purple-seed-stain";
  if((leaf-malf=="present") && (leafspots-halo=="no-yellow-halos") && (leaf-mild=="absent"))
    return "phyllosticta-leaf-spot";
  if((date=="june") && (precip=="lt-norm"))
    return "phyllosticta-leaf-spot";
  if((fruiting-bodies=="present") && (fruit-spots=="dna"))
    return "diaporthe-stem-canker";
  if((leafspots-marg=="no-w-s-marg"))
    return "bacterial-pustule";
  if((leafspot-size=="lt-1"))
    return "bacterial-blight";
  if((int-discolor=="black"))
    return "charcoal-rot";
  if((fruit-pods=="dna") && (canker-lesion=="brown"))
    return "rhizoctonia-root-rot";
  if((leaf-mild=="lower-surf"))
    return "downy-mildew";
  if((fruit-spots=="brown-w") && (leafspots-halo=="absent"))
    return "anthracnose";
  if((seed=="abnorm") && (leafspots-halo=="absent"))
    return "anthracnose";
  if((int-discolor=="brown"))
    return "brown-stem-rot";
  if((plant-growth=="abnorm") && (canker-lesion=="dk-brown-blk"))
    return "phytophthora-rot";
  if((stem=="norm") && (date=="september"))
    return "alternarialeaf-spot";
  if((canker-lesion=="dna") && (date=="october"))
    return "alternarialeaf-spot";
  if((stem=="norm") && (date=="august") && (seed-tmt=="none"))
    return "alternarialeaf-spot";
  if((fruit-pods=="diseased"))
    return "frog-eye-leaf-spot";
  if((date=="august") && (temp=="gt-norm"))
    return "frog-eye-leaf-spot";
  if((date=="august") && (germination=="90-100") && (leaf-shread=="absent"))
    return "frog-eye-leaf-spot";
  if((date=="september") && (severity=="minor"))
    return "frog-eye-leaf-spot";
  else
    return "brown-spot";

}