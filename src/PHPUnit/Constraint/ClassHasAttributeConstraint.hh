<?hh // strict

namespace PHPUnit\Constraint;

/*
 * This file is part of PHPUnit.
 *
 * (c) Sebastian Bergmann <sebastian@phpunit.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

use PHPUnit\Constraint\Base as ConstraintBase;
use \ReflectionClass;

/**
 * Constraint that asserts that the class it is evaluated for has a given
 * attribute.
 *
 * The attribute name is passed in the constructor.
 *
 * @since Class available since Release 3.1.0
 */
class ClassHasAttributeConstraint extends ConstraintBase {

    /**
     * @var string
     */
    protected string $attributeName;

    /**
     * @param string $attributeName
     */
    public function __construct(mixed $attributeName) {
      parent::__construct();
      $this->attributeName = strval($attributeName);
    }

    /**
     * Evaluates the constraint for parameter $other. Returns true if the
     * constraint is met, false otherwise.
     *
     * @param mixed $other Value or object to evaluate.
     *
     * @return bool
     */
    public function matches(mixed $other): bool {
      $class = new ReflectionClass($other);
      return $class->hasProperty($this->attributeName);
    }

    /**
     * Returns a string representation of the constraint.
     *
     * @return string
     */
    public function toString(): string {
      return sprintf('has attribute "%s"', $this->attributeName);
    }

    /**
     * Returns the description of the failure
     *
     * The beginning of failure messages is "Failed asserting that" in most
     * cases. This method should return the second part of that sentence.
     *
     * @param mixed $other Evaluated value or object.
     *
     * @return string
     */
    public function failureDescription(mixed $other): string {
      return sprintf(
        '%sclass "%s" %s',
        is_object($other) ? 'object of ' : '',
        is_object($other) ? get_class($other) : $other,
        $this->toString()
      );
    }
}
