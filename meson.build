project('mbeccariBioinformatica2023', 'cpp')

include_dirs = [
    include_directories('include')
]

sources = [
    'src/main.cpp',
    'src/seeds.cpp']

ntHash_proj = subproject('ntHash')
nthash_lib = ntHash_proj.get_variable('nthash_lib')
nthash_include = ntHash_proj.get_variable('include_dirs')

executable(
    'mbeccariBioinformatica2023',
    sources,
    link_with  : nthash_lib,
    include_directories: [nthash_include, include_dirs])