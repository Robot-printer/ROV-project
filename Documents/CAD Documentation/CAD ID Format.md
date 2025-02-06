For consistency and readability Cad files should be named in this ID format
# How You Should ID Your Part
Part initial, Part number(two digits)_Part Version major. Part Version minor
`P##_#.#`
##  Examples of Base Format 
The base format is 
 `P##_#.#`
 lets use Skeleton part one Version 1.1 this would look like
 `S01_1.1`
 If we make a minor change to the design say making it fit better we now change the version number to 1.2
 `S01_1.2`  
 And if we change the part drastically we change the major version number and reset the minor to 1
 `S01_2.1`
### Special Cases
#### Part Initial is already takin
Example: you just made part but its Initial was already taken by another part the newer part(The part you just made) will now have a second initial.
(Original part)--->`P01_1.1`
(Newer part) ---> `Pi01_1.1`
 
  