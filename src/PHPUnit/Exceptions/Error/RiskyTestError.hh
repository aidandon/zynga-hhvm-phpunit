<?hh // strict
/*
 * This file is part of PHPUnit.
 *
 * (c) Sebastian Bergmann <sebastian@phpunit.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPUnit\Exceptions\Error;

use PHPUnit\Exceptions\Error\Base as ErrorBase;
use PHPUnit\Interfaces\RiskyTestInterface;

/**
 * Extension to AssertionFailedError to mark the special
 * case of a risky test.
 *
 * @since Class available since Release 4.0.0
 */
class RiskyTestError extends ErrorBase implements RiskyTestInterface {
}
