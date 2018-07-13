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
use \ArrayAccess;

/**
 * Constraint that asserts that the array it is evaluated for has a given key.
 *
 * Uses array_key_exists() to check if the key is found in the input array, if
 * not found the evaluation fails.
 *
 * The array key is passed in the constructor.
 *
 * @since Class available since Release 3.0.0
 */
class ArrayHasKeyConstraint extends ConstraintBase
{
    /**
     * @var int|string
     */
    protected mixed $key;

    /**
     * @param int|string $key
     */
    public function __construct(mixed $key) {
        parent::__construct();
        $this->key = $key;
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
        if (is_array($other)) {
          return array_key_exists($this->key, $other);
        }

        if ($other instanceof ArrayAccess) {
          return $other->offsetExists($this->key);
        }

        return false;
    }

    /**
     * Returns a string representation of the constraint.
     *
     * @return string
     */
    public function toString(): string {
        return 'has the key ' . $this->exporter->export($this->key);
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
        return 'an array ' . $this->toString();
    }
}
