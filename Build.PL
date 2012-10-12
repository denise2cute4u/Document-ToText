#!/usr/bin/perl

use strict;
use warnings;

use Module::Build::WithXSpp;

my $build = Module::Build::WithXSpp->new( extra_compiler_flags => [ '-std=c++0x', split / /, `pkg-config --cflags libwpd-0.9 libwps-0.2 wv-1.0` ],
                                            extra_linker_flags => [               split / /, `pkg-config --libs   libwpd-0.9 libwps-0.2 wv-1.0` ],
                                         extra_typemap_modules => { 'ExtUtils::Typemap::ObjectMap' => '0.01' },
                                                       license => 'perl',
                                                   module_name => 'Document::ToText',
                                                      requires => {} )->create_build_script;