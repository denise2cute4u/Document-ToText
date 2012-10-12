#!/usr/bin/perl

use strict;
use warnings;

use Module::Build::WithXSpp;

my @cc_flags = ( '-std=c++0x', split / /, `pkg-config --cflags libwpd-0.9 libwps-0.2 wv-1.0` );
my @ld_flags =                 split / /, `pkg-config --libs   libwpd-0.9 libwps-0.2 wv-1.0`;

Module::Build::WithXSpp->new( configure_requires => { 'Module::Build' => 0 },
                            extra_compiler_flags => \@cc_flags,
                              extra_linker_flags => \@ld_flags,
                           extra_typemap_modules => { 'ExtUtils::Typemap::ObjectMap' => 0 },
                                         license => 'perl',
                                     module_name => 'Document::ToText',
                                        requires => { 'File::LibMagic' => 0 } )->create_build_script;