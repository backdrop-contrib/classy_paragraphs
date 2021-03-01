# Classy Paragraphs

Classy paragraphs ships a new field type "Class list" which allows an editor to
apply a selected class to paragraph items via a drop-down list. Site builders
can add this functionality by creating a custom "Class list" field. Classes can
be added by implementing the `hook_classy_paragraphs_list_options` hook, or
through the UI with the included *Classy Paragraphs UI* sub-module.

## Dependencies

- Paragraphs
- List
- Options
 
## Installation and Usage

- Install this module using the [official Backdrop CMS instructions](https://backdropcms.org/guide/modules).
- Add "Class list" field to desired paragraph type
- Define classes by:
    - implementing the the `hook_classy_paragraphs_list_options` hook, OR
    - Activating the *Classy Paragraphs UI* sub-module and adding classes at 
      **Configuration > Content authoring > Classy Paragraphs UI**
- Further instructions can be found in (and added to) the [Wiki](https://github.com/backdrop-contrib/classy_paragraphs/wiki)

## Issues

Bugs and Feature requests should be reported in the [Issue Queue](https://github.com/backdrop-contrib/classy_paragraphs/issues)

## Current Maintainers

- [Laryn Kragt Bakker](https://github.com/laryn/), [CEDC.org](https://CEDC.org) 

## Credits

- Ported to Backdrop CMS by [Laryn Kragt Bakker](https://github.com/laryn/), [CEDC.org](https://CEDC.org)
- The Drupal 7 version is maintained by [Ivan Trokhanenko](https://www.drupal.org/u/i-trokhanenko)
  and [Ivan Zugec](https://www.drupal.org/u/ivan-zugec), and has been supported
  by [Morpht](https://www.drupal.org/morpht) and
  [RockSolid PSF](https://www.drupal.org/rocksolid-psf).
- The *Classy Paragraphs UI* sub-module was initially developed by
  [Mark Breneman](https://www.drupal.org/u/dervishmoose).

## License

This project is GPL v2 software. See the LICENSE.txt file in this directory for
complete text.
