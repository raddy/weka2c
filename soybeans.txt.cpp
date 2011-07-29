#include <iostream>

using namespace std;

string classify(string leafspot, string leafspots, string leaf, string precip, string int, string leaves, string area, string fruiting, string canker, string stem, string plant, string fruit, string seed, string crop, string date, string mold, string roots){

  if (leafspot = lt-1){
    if (canker = dna){
      if (leafspots = w-s-marg){
        if (seed = norm){
          return "bacterial-blight";
        }
        else{
          return "bacterial-pustule";
        }
      }
      else{
        return "bacterial-pustule";
      }
      else{
        return "bacterial-blight";
      }
    }
    else{
      return "bacterial-blight";
    }
    else{
      return "phytophthora-rot";
    }
    else{
      return "purple-seed-stain";
    }
  }
  else{
    if (roots = norm){
      if (mold = absent){
        if (fruit = absent){
          if (leaf = absent){
            if (fruiting = absent){
              if (date = april){
                return "brown-spot";
              }
              else{
                return "brown-spot";
              }
              else{
                if (precip = lt-norm){
                  return "phyllosticta-leaf-spot";
                }
                else{
                  return "brown-spot";
                }
                else{
                  return "brown-spot";
                }
              }
              else{
                if (precip = lt-norm){
                  return "phyllosticta-leaf-spot";
                }
                else{
                  return "phyllosticta-leaf-spot";
                }
                else{
                  return "frog-eye-leaf-spot";
                }
              }
              else{
                if (leaf = absent){
                  if (seed = none){
                    return "alternarialeaf-spot";
                  }
                  else{
                    if (plant = normal){
                      return "frog-eye-leaf-spot";
                    }
                    else{
                      return "alternarialeaf-spot";
                    }
                  }
                  else{
                    return "frog-eye-leaf-spot";
                  }
                }
                else{
                  return "alternarialeaf-spot";
                }
              }
              else{
                if (stem = norm){
                  return "alternarialeaf-spot";
                }
                else{
                  return "frog-eye-leaf-spot";
                }
              }
              else{
                return "alternarialeaf-spot";
              }
            }
            else{
              return "brown-spot";
            }
          }
          else{
            return "phyllosticta-leaf-spot";
          }
        }
        else{
          if (fruit = norm){
            return "brown-spot";
          }
          else{
            return "frog-eye-leaf-spot";
          }
          else{
            return "frog-eye-leaf-spot";
          }
          else{
            return "frog-eye-leaf-spot";
          }
        }
        else{
          if (crop = diff-lst-year){
            return "brown-spot";
          }
          else{
            return "brown-spot";
          }
          else{
            return "brown-spot";
          }
          else{
            return "frog-eye-leaf-spot";
          }
        }
        else{
          return "brown-spot";
        }
        else{
          return "brown-stem-rot";
        }
      }
      else{
        if (leaves = norm){
          return "diaporthe-pod-";
        }
        else{
          return "downy-mildew";
        }
      }
    }
    else{
      if (area = scattered){
        return "herbicide-injury";
      }
      else{
        return "phytophthora-rot";
      }
      else{
        return "phytophthora-rot";
      }
      else{
        return "herbicide-injury";
      }
    }
    else{
      return "cyst-nematode";
    }
  }
  else{
    if (int = none){
      if (leaves = norm){
        if (stem = absent){
          if (canker = dna){
            return "diaporthe-pod-";
          }
          else{
            return "purple-seed-stain";
          }
          else{
            return "purple-seed-stain";
          }
          else{
            return "purple-seed-stain";
          }
        }
        else{
          return "rhizoctonia-root-rot";
        }
        else{
          return "anthracnose";
        }
        else{
          return "anthracnose";
        }
      }
      else{
        if (stem = norm){
          if (plant = norm){
            return "powdery-mildew";
          }
          else{
            return "cyst-nematode";
          }
        }
        else{
          if (plant = normal){
            if (leaf = absent){
              if (seed = norm){
                return "diaporthe-stem-canker";
              }
              else{
                return "anthracnose";
              }
            }
            else{
              return "2-4-d-injury";
            }
          }
          else{
            if (fruiting = absent){
              return "phytophthora-rot";
            }
            else{
              if (roots = norm){
                return "anthracnose";
              }
              else{
                return "phytophthora-rot";
              }
              else{
                return "phytophthora-rot";
              }
            }
          }
        }
      }
    }
    else{
      if (leaf = absent){
        return "brown-stem-rot";
      }
      else{
        return "2-4-d-injury";
      }
    }
    else{
      return "charcoal-rot";
    }
  }

}