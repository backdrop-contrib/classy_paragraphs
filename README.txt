Classy paragraphs ships a new field type "Class list" which allows an editor to apply a selected class to paragraphs.

## How to use

Create a "Class list" field on your paragraph's bundle. Classes are added by implementing the `hook_classy_paragraph_list_options`.

## How this module works

This module allows an editor to select a class which is then added to the paragraph template.

The class is added to the template via the `classy_paragraphs_preprocess_entity` preprocess function. In this function we use `classy_paragraphs_get_class` to pull out the selected class from the paragraph_item entity. Once we have a class, then we add it to the template using `$variables['classes_array']`.