#include <iostream>

using namespace std;

string classify(string seed, string area-damaged, string int-discolor, string leaf-malf, string roots, string crop-hist, string canker-lesion, string precip, string leafspots-marg, string leafspot-size, string mold-growth, string fruiting-bodies, string seed-size, string leaf-shread, string fruit-spots, string stem, string date, string plant-growth, string plant-stand, string seed-tmt, string leaves, string stem-cankers, string fruit-pods){

  if (leafspot-size == "lt-1"){
    if (canker-lesion == "dna"){
      if (leafspots-marg == "w-s-marg"){
        if (seed-size == "norm"){
          return "bacterial-blight";
        }
        elseif (seed-size == "lt-norm"){
          return "bacterial-pustule";
        }
      }
      elseif (leafspots-marg == "no-w-s-marg"){
        return "bacterial-pustule";
      }
      elseif (leafspots-marg == "dna"){
        return "bacterial-blight";
      }
    }
    elseif (canker-lesion == "brown"){
      return "bacterial-blight";
    }
    elseif (canker-lesion == "dk-brown-blk"){
      return "phytophthora-rot";
    }
    elseif (canker-lesion == "tan"){
      return "purple-seed-stain";
    }
  }
  elseif (leafspot-size == "gt-1"){
    if (roots == "norm"){
      if (mold-growth == "absent"){
        if (fruit-spots == "absent"){
          if (leaf-malf == "absent"){
            if (fruiting-bodies == "absent"){
              if (date == "april"){
                return "brown-spot";
              }
              elseif (date == "may"){
                return "brown-spot";
              }
              elseif (date == "june"){
                if (precip == "lt-norm"){
                  return "phyllosticta-leaf-spot";
                }
                elseif (precip == "norm"){
                  return "brown-spot";
                }
                elseif (precip == "gt-norm"){
                  return "brown-spot";
                }
              }
              elseif (date == "july"){
                if (precip == "lt-norm"){
                  return "phyllosticta-leaf-spot";
                }
                elseif (precip == "norm"){
                  return "phyllosticta-leaf-spot";
                }
                elseif (precip == "gt-norm"){
                  return "frog-eye-leaf-spot";
                }
              }
              elseif (date == "august"){
                if (leaf-shread == "absent"){
                  if (seed-tmt == "none"){
                    return "alternarialeaf-spot";
                  }
                  elseif (seed-tmt == "fungicide"){
                    if (plant-stand == "normal"){
                      return "frog-eye-leaf-spot";
                    }
                    elseif (plant-stand == "lt-normal"){
                      return "alternarialeaf-spot";
                    }
                  }
                  elseif (seed-tmt == "other"){
                    return "frog-eye-leaf-spot";
                  }
                }
                elseif (leaf-shread == "present"){
                  return "alternarialeaf-spot";
                }
              }
              elseif (date == "september"){
                if (stem == "norm"){
                  return "alternarialeaf-spot";
                }
                elseif (stem == "abnorm"){
                  return "frog-eye-leaf-spot";
                }
              }
              elseif (date == "october"){
                return "alternarialeaf-spot";
              }
            }
            elseif (fruiting-bodies == "present"){
              return "brown-spot";
            }
          }
          elseif (leaf-malf == "present"){
            return "phyllosticta-leaf-spot";
          }
        }
        elseif (fruit-spots == "colored"){
          if (fruit-pods == "norm"){
            return "brown-spot";
          }
          elseif (fruit-pods == "diseased"){
            return "frog-eye-leaf-spot";
          }
          elseif (fruit-pods == "few-present"){
            return "frog-eye-leaf-spot";
          }
          elseif (fruit-pods == "dna"){
            return "frog-eye-leaf-spot";
          }
        }
        elseif (fruit-spots == "brown-w"){
          if (crop-hist == "diff-lst-year"){
            return "brown-spot";
          }
          elseif (crop-hist == "same-lst-yr"){
            return "brown-spot";
          }
          elseif (crop-hist == "same-lst-two-yrs"){
            return "brown-spot";
          }
          elseif (crop-hist == "same-lst-sev-yrs"){
            return "frog-eye-leaf-spot";
          }
        }
        elseif (fruit-spots == "distort"){
          return "brown-spot";
        }
        elseif (fruit-spots == "dna"){
          return "brown-stem-rot";
        }
      }
      elseif (mold-growth == "present"){
        if (leaves == "norm"){
          return "diaporthe-pod-";
        }
        elseif (leaves == "abnorm"){
          return "downy-mildew";
        }
      }
    }
    elseif (roots == "rotted"){
      if (area-damaged == "scattered"){
        return "herbicide-injury";
      }
      elseif (area-damaged == "low-areas"){
        return "phytophthora-rot";
      }
      elseif (area-damaged == "upper-areas"){
        return "phytophthora-rot";
      }
      elseif (area-damaged == "whole-field"){
        return "herbicide-injury";
      }
    }
    elseif (roots == "galls-cysts"){
      return "cyst-nematode";
    }
  }
  elseif (leafspot-size == "dna"){
    if (int-discolor == "none"){
      if (leaves == "norm"){
        if (stem-cankers == "absent"){
          if (canker-lesion == "dna"){
            return "diaporthe-pod-";
          }
          elseif (canker-lesion == "brown"){
            return "purple-seed-stain";
          }
          elseif (canker-lesion == "dk-brown-blk"){
            return "purple-seed-stain";
          }
          elseif (canker-lesion == "tan"){
            return "purple-seed-stain";
          }
        }
        elseif (stem-cankers == "below-soil"){
          return "rhizoctonia-root-rot";
        }
        elseif (stem-cankers == "above-soil"){
          return "anthracnose";
        }
        elseif (stem-cankers == "above-sec-nde"){
          return "anthracnose";
        }
      }
      elseif (leaves == "abnorm"){
        if (stem == "norm"){
          if (plant-growth == "norm"){
            return "powdery-mildew";
          }
          elseif (plant-growth == "abnorm"){
            return "cyst-nematode";
          }
        }
        elseif (stem == "abnorm"){
          if (plant-stand == "normal"){
            if (leaf-malf == "absent"){
              if (seed == "norm"){
                return "diaporthe-stem-canker";
              }
              elseif (seed == "abnorm"){
                return "anthracnose";
              }
            }
            elseif (leaf-malf == "present"){
              return "2-4-d-injury";
            }
          }
          elseif (plant-stand == "lt-normal"){
            if (fruiting-bodies == "absent"){
              return "phytophthora-rot";
            }
            elseif (fruiting-bodies == "present"){
              if (roots == "norm"){
                return "anthracnose";
              }
              elseif (roots == "rotted"){
                return "phytophthora-rot";
              }
              elseif (roots == "galls-cysts"){
                return "phytophthora-rot";
              }
            }
          }
        }
      }
    }
    elseif (int-discolor == "brown"){
      if (leaf-malf == "absent"){
        return "brown-stem-rot";
      }
      elseif (leaf-malf == "present"){
        return "2-4-d-injury";
      }
    }
    elseif (int-discolor == "black"){
      return "charcoal-rot";
    }
  }

}