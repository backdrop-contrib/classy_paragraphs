<?php

/**
 * @file
 * Implements custom field: cp_list (CLASSY_PARAGRAPHS_FIELD_TYPE_LIST).
 *
 */

/**
 * Implements hook_field_info().
 */
function classy_paragraphs_field_info() {
  return array(
    CLASSY_PARAGRAPHS_FIELD_TYPE_LIST => array(
      'label' => t('Class list'),
      'description' => t('This field stores a selected class.'),
      'default_widget' => 'options_select',
      'default_formatter' => 'list_default',
      'instance_settings' => array(
        'classy_paragraphs_set' => '',
      ),
      // Setting below are necessary for "options_select" widget and
      // "list_default" formatter to work correctly without warnings.
      'settings' => array(
        'allowed_values' => array(),
        'allowed_values_function' => '',
      ),
    ),
  );
}

/**
 * Implements hook_field_is_empty().
 */
function classy_paragraphs_field_is_empty($item, $field) {
  if (empty($item['value'])) {
    return TRUE;
  }
  return FALSE;
}

/**
 * Implements hook_field_validate().
 */
function classy_paragraphs_field_validate($entity_type, $entity, $field, $instance, $langcode, $items, &$errors) {
  foreach ($items as $delta => $item) {
    if (!empty($item['value'])) {
      $selected = $item['value'];
      $possible_options = classy_paragraphs_get_options($field, $instance);

      // Validate the selected option.
      if (!isset($possible_options[$selected])) {
        $errors[$field['field_name']][$langcode][$delta][] = array(
          'error' => 'cp_list_invalid',
          'message' => t('Selected option "%selected" is not allowed.', array(
            '%selected' => $selected,
          )),
        );
      }
    }
  }
}

/**
 * Implements hook_field_widget_info_alter().
 *
 * The CLASSY_PARAGRAPHS_FIELD_TYPE_LIST field type does not implement widgets of its own, but reuses the
 * widget defined in options.module.
 *
 * @see paragraphs_pack_options_list()
 */
function classy_paragraphs_field_widget_info_alter(&$info) {
  $widgets = array(
    'options_select' => array(CLASSY_PARAGRAPHS_FIELD_TYPE_LIST),
    'options_buttons' => array(CLASSY_PARAGRAPHS_FIELD_TYPE_LIST),
  );

  foreach ($widgets as $widget => $field_types) {
    $info[$widget]['field types'] = array_merge($info[$widget]['field types'], $field_types);
  }
}

/**
 * Implements hook_options_list().
 */
function classy_paragraphs_options_list($field, $instance, $entity_type, $entity) {
  $options = array();

  switch ($field['type']) {
    case CLASSY_PARAGRAPHS_FIELD_TYPE_LIST:
      $options = classy_paragraphs_get_options($field, $instance);
      break;
  }

  return $options;
}

/**
 * Implements hook_field_instance_settings_form().
 */
function classy_paragraphs_field_instance_settings_form($field, $instance) {
  if (module_exists('classy_paragraphs_ui')) {
    $settings = $instance['settings'];
    $form = array();

    // Allow this field to be limited to classes in a particular set.
    $sets_array = config_get('classy_paragraphs_ui.sets');
    if (!empty($sets_array)) {
      $class_options = array();
      foreach ($sets_array as $set) {
        if ($set) {
          $class_options[$set['name']] = $set['label'];
        }
      }
      $form['classy_paragraphs_set'] =  array(
        '#title'   => t('Limit to classes in a particular set'),
        '#type'    => 'select',
        '#options' => $class_options,
        '#default_value' => isset($settings['classy_paragraphs_set']) ? $settings['classy_paragraphs_set'] : '',
        '#empty' => t('- Show all -'),
      );
      $form['classy_paragraphs_set_include'] = array(
        '#type' => 'checkbox',
        '#title' => t('Include the selected set name with the class'),
        '#description' => t('If enabled, the class set name will be included along with the class name when building the content.'),
        '#default_value' => isset($settings['classy_paragraphs_set_include']) ? $settings['classy_paragraphs_set_include'] : FALSE,
      );
    }

    return $form;
  }
}

