project(
  'crash',
  'c',
  version: '1.0.0'
)


add_project_arguments('-O0', '-g', language : 'c')

gtk = dependency('gtk4', version: '>= 4.6.0')
adwaita = dependency('libadwaita-1', version: '>=1.2.0')


executable('crasher', 'main.c', dependencies: [adwaita, gtk])
