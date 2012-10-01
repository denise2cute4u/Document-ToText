#!/usr/bin/perl

use strict;
use warnings;

use Module::Build::WithXSpp;

my $build = Module::Build::WithXSpp->new( extra_compiler_flags => [ split / /, `pkg-config --cflags libwpd-0.9 libwps-0.2` ],
                                            extra_linker_flags => [ split / /, `pkg-config --libs   libwpd-0.9 libwps-0.2` ],
                                         extra_typemap_modules => { 'ExtUtils::Typemap::ObjectMap' => '0.01' },
                                                       license => 'perl',
                                                   module_name => 'Text::Convert::Plugin::application_msworks',
                                                      requires => {} )->create_build_script;