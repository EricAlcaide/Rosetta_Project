// pruning an object recursively to remove any undefined, null or empty values.

import _ from 'lodash';

export default function pruneEmpty(obj) {
  return (function prune(current) {
    _.forOwn(current, (value, key) => {
      if (_.isUndefined(value) || _.isNull(value) || _.isNaN(value) ||
        (_.isString(value) && _.isEmpty(value)) ||
        (_.isObject(value) && _.isEmpty(prune(value)))) {
        delete current[key];
      }
    });
    // remove any leftover undefined values from the delete
    // operation on an array
    if (_.isArray(current)) {
      _.pull(current, undefined);
    }
    return current;
  })(_.cloneDeep(obj));  // Do not modify the original object, create a clone instead
}
