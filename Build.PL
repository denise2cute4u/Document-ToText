use strict;
use warnings;

use Module::Build::WithXSpp;

my $libs = 'libwpd-0.9 libwps-0.2 wv-1.0';

Module::Build::WithXSpp->new( configure_requires => { 'Module::Build' => 0 },
                            extra_compiler_flags => [ split / /, `pkg-config --cflags $libs` ],
                              extra_linker_flags => [ split / /, `pkg-config --libs   $libs` ],
                           extra_typemap_modules => { 'ExtUtils::Typemaps::STL::String' => 0 },
                                         license => 'perl',
                                     module_name => 'Document::ToText',
                                        requires => { 'File::LibMagic' => 0 } )->create_build_script;