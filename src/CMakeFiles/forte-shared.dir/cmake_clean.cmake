file(REMOVE_RECURSE
  "libforte-shared.pdb"
  "libforte-shared.so"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/forte-shared.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
